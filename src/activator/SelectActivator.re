open Country;
open ReactUtils;

let style =
  ReactDOMRe.Style.make(
    ~display="block",
    ~width="50%",
    ~height="25px",
    ~backgroundColor="#FFFFFF",
    ~marginBottom="2px",
    ~border="1px solid #000000",
    ~borderRadius="3%",
    (),
  );

let styleIcoContainer =
  ReactDOMRe.Style.make(~width="20px", ~float="right", ~paddingTop="3px", ());

let labelStyle = ReactDOMRe.Style.make(~overflow="hidden", ());

[@react.component]
let make = (~selectedCountry, ~searchIsOpen, ~onClick, ~isLoading) =>
  <div style onClick>
    <div style=styleIcoContainer>
      {isLoading ? <Loading /> : <ActivatorIcon active=searchIsOpen />}
    </div>
    <span style=labelStyle>
      {(
         switch (selectedCountry) {
         | None => ""
         | Some(c) => c.label
         }
       )
       |> s}
    </span>
  </div>;
