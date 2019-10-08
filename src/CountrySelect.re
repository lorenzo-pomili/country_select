// <CountrySelect
//   className="custom-class"
//   country=Some("us")
//   onChange=(country => Js.log(country))
// />
open Country;
open React;
open ReactUtils;
open Belt;

let containerSytle = ReactDOMRe.Style.make(~width="250px", ());

let url = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

type state = {
  options: array(t),
  filteredOptions: array(t),
  selectedCountry: option(t),
  searchIsOpen: bool,
  isLoading: bool,
};

type action =
  | SetLoading(bool)
  | ToggleSearchIsOpen
  | SelectCountry(option(t))
  | SetFilteredOptions(array(t))
  | SetOptions(array(t));

let getSelectedCountry = (c, arr: array(t)) =>
  switch (c) {
  | None => None
  | Some(value) => Array.getBy(arr, e => e.value === value)
  };

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

[@react.component]
let make =
    (
      ~className: string,
      ~country: option(countryId),
      ~onChange: option(t) => unit,
    ) => {
  let (state, dispatcher) =
    useReducer(
      (state, action) =>
        switch (action) {
        | SetLoading(v) => {...state, isLoading: v}
        | SetFilteredOptions(filteredOptions) => {...state, filteredOptions}
        | SetOptions(options) => {...state, options}
        | SelectCountry(country) => {...state, selectedCountry: country}
        | ToggleSearchIsOpen => {...state, searchIsOpen: !state.searchIsOpen}
        },
      {
        options: [||],
        filteredOptions: [||],
        selectedCountry: None,
        searchIsOpen: false,
        isLoading: false,
      },
    );

  useEffect0(() => {
    dispatcher(SetLoading(true));
    Js.Promise.(
      HttpService.get(url, jsonArrayDecoder)
      |> then_(options =>
           {
             dispatcher(SetOptions(options));
             dispatcher(SetLoading(false));
           }
           |> resolve
         )
      |> ignore
    );
    None;
  });

  useEffect2(
    () => {
      let selected = getSelectedCountry(country, state.options);
      SelectCountry(selected) |> dispatcher;
      None;
    },
    (country, state.options),
  );

  <div style=containerSytle>
    <SelectActivator
      isLoading={state.isLoading}
      searchIsOpen={state.searchIsOpen}
      onClick={_ => state.isLoading ? () : dispatcher(ToggleSearchIsOpen)}
      selectedCountry={state.selectedCountry}
    />
    <div
      style={ReactDOMRe.Style.make(
        ~width="100%",
        ~display="inline-block",
        (),
      )}>
      {state.searchIsOpen
         ? <CustomSelect
             className
             selectedOption={state.selectedCountry}
             selectedToJs={sC =>
               switch (sC) {
               | None => None
               | Some(c) => Some({"value": c.value, "label": c.label})
               }
             }
             placeholder={<span> <SearchIcon /> {"Search" |> s} </span>}
             options={state.options}
             menuIsOpen=true
             isClearable=true
             isSearchable=true
             filterOption={(o, s) => shouldShow(state.options, s, o##data)}
             indicatorSeparator={_ => React.null}
             dropdownIndicator={_ => React.null}
             elementOfOption={props => <SingleOption props />}
             input={props => <SearchInput props />}
             onChange={c => {
               let optC = Js.Nullable.toOption(c);
               dispatcher(SelectCountry(optC));
               onChange(optC);
             }}
           />
         : React.null}
    </div>
  </div>;
};
