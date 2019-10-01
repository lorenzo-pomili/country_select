// <CountrySelect
//   className="custom-class"
//   country=Some("us")
//   onChange=(country => Js.log(country))
// />
open Country;
open React;

let url = "https://gist.githubusercontent.com/rusty-key/659db3f4566df459bd59c8a53dc9f71f/raw/4127f9550ef063121c564025f6d27dceeb279623/counties.json";

type state = {
  options: array(Country.t),
  selectedCountry: option(Country.t),
};

type action =
  | SelectCountry(option(Country.t))
  | SetOptions(array(Country.t));

let getSelectedCountry = (c, arr: array(Country.t)) =>
  switch (c) {
  | None => None
  | Some(value) => Belt.Array.getBy(arr, e => e.value === value)
  };

[@react.component]
let make =
    (
      ~className: string,
      ~country: option(Country.countryId),
      ~onChange: Country.t => unit,
    ) => {
  let (state, dispatcher) =
    useReducer(
      (state, action) =>
        switch (action) {
        | SetOptions(options) => {...state, options}
        | SelectCountry(country) => {...state, selectedCountry: country}
        },
      {options: [||], selectedCountry: None},
    );

  useEffect0(() => {
    Js.Promise.(
      HttpService.get(url, Country.jsonArrayDecoder)
      |> then_(options => dispatcher(SetOptions(options)) |> resolve)
      |> ignore
    );
    None;
  });

  useEffect2(
    () => {
      SelectCountry(getSelectedCountry(country, state.options)) |> dispatcher;
      None;
    },
    (country, state.options),
  );
  <div>
    <CustomSelect
      className
      selectedOption={state.selectedCountry}
      options={state.options}
      stringOfOption={op => op.label}
      onChange={c => {
        dispatcher(SelectCountry(Some(c)));
        onChange(c);
      }}
    />
  </div>;
};
