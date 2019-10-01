// <CountrySelect
//   className="custom-class"
//   country=Some("us")
//   onChange=(country => Js.log(country))
// />
open React;

[@react.component]
let make =
    (
      ~className: string,
      ~country: option(Country.countryId),
      ~onChange: Country.t => unit,
    ) =>
  <div> {string(className)} </div>;
