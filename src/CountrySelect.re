// <CountrySelect
//   className="custom-class"
//   country=Some("us")
//   onChange=(country => Js.log(country))
// />
open Country;
open React;
open ReactUtils;

let containerSytle = ReactDOMRe.Style.make(~width="250px", ());

let url = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

type state = {
  options: array(t),
  selectedCountry: option(t),
  searchIsOpen: bool,
  isLoading: bool,
};

type action =
  | SetLoading(bool)
  | ToggleSearchIsOpen
  | SelectCountry(option(t))
  | SetOptions(array(t));

let getSelectedCountry = (c, arr: array(t)) =>
  switch (c) {
  | None => None
  | Some(value) => Belt.Array.getBy(arr, e => e.value === value)
  };

let optionFilter = (option, searchString) =>
  Js.String.includes(
    Js.String.toLowerCase(searchString),
    Js.String.toLowerCase(option.label),
  );

[@react.component]
let make =
    (~className: string, ~country: option(countryId), ~onChange: t => unit) => {
  let (state, dispatcher) =
    useReducer(
      (state, action) =>
        switch (action) {
        | SetLoading(v) => {...state, isLoading: v}
        | SetOptions(options) => {...state, options}
        | SelectCountry(country) => {...state, selectedCountry: country}
        | ToggleSearchIsOpen => {...state, searchIsOpen: !state.searchIsOpen}
        },
      {
        options: [||],
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
           filterOption={(o, s) => optionFilter(o##data, s)}
           indicatorSeparator={_ => React.null}
           dropdownIndicator={_ => React.null}
           elementOfOption={props =>
             <div key={props##data.value}>
               <ReactSelect.Option
                 cx=props##cx
                 clearValue=props##clearValue
                 theme=props##theme
                 getStyles=props##getStyles
                 getValue=props##getValue
                 hasValue=props##hasValue
                 options=props##options
                 setValue=props##setValue
                 selectOption=props##selectOption
                 isFocused=props##isFocused
                 isMulti=props##isMulti
                 isRtl=props##isRtl
                 isDisabled=props##isDisabled
                 isSelected=props##isSelected
                 selectProps=props##selectProps
                 innerProps=props##innerProps
                 data=props##data
                 label=props##label
                 value=props##value
                 innerRef=props##innerRef>
                 <>
                   <Flag nationCode={props##data.value} />
                   {props##data.label |> s}
                 </>
               </ReactSelect.Option>
             </div>
           }
           onChange={c => {
             dispatcher(SelectCountry(Some(c)));
             onChange(c);
           }}
         />
       : React.null}
  </div>;
};
