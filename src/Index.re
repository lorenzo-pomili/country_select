ReactDOMRe.renderToElementWithId(
  <CountrySelect
    className="custom-class"
    country=None
    onChange={country => Js.log(country)}
  />,
  "countrySelect",
);
