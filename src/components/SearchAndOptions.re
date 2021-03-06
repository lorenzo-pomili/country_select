open ReactUtils;
open Country;
open Belt;

let optionFilter = (searchString, option) =>
  Js.String.includes(
    Js.String.toLowerCase(searchString),
    Js.String.toLowerCase(option.label),
  )
  && searchString !== "";

let shouldShow = (options, searchString, option) => {
  let filteredOptions = options->Array.keep(optionFilter(searchString));
  filteredOptions->Array.some(o => o.value === option.value);
};

let selectedToJs = sC =>
  switch (sC) {
  | None => None
  | Some(c) => Some({"value": c.value, "label": c.label})
  };

let isSearching = ref(false);

[@react.component]
let make = (~options, ~selectedCountry, ~onChange) => {
  <ReactSelect
    options
    value={Js.Nullable.fromOption(selectedToJs(selectedCountry))}
    menuIsOpen=true
    onChange
    isClearable=true
    isSearchable=true
    placeholder={<span> <SearchIcon /> {"Search" |> s} </span>}
    components={
      "Option": props => <SingleOption props />,
      "IndicatorSeparator": _ => React.null,
      "DropdownIndicator": _ => React.null,
      "Menu": props => <Menu props />,
      "Input": props => <SearchInput props />,
      "NoOptionsMessage": props =>
        ! isSearching^
          ? <NoOptionsMessage props>
              {{options |> Array.length |> Belt.Int.toString}
               ++ " countries available"
               |> s}
            </NoOptionsMessage>
          : <NoOptionsMessage props> {"No Countries" |> s} </NoOptionsMessage>,
    }
    filterOption={(o, s) => {
      s === "" ? isSearching := false : isSearching := true;
      shouldShow(options, s, o##data);
    }}
  />;
};
