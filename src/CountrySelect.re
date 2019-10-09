// <CountrySelect
//   className="custom-class"
//   country=Some("us")
//   onChange=(country => Js.log(country))
// />
open Country;
open React;
open Belt;

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
  | Some(value) => Array.getBy(arr, e => e.value === value)
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

  <div className style=containerSytle>
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
         ? <SearchAndOptions
             options={state.options}
             selectedCountry={state.selectedCountry}
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
