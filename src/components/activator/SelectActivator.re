open Country;
open ReactUtils;

let style =
  ReactDOMRe.Style.make(
    ~width="50%",
    ~height="25px",
    ~backgroundColor="#FFFFFF",
    ~marginBottom="2px",
    ~border="1px solid #000000",
    ~borderRadius="3%",
    (),
  );

let styleIcoContainer =
  ReactDOMRe.Style.make(
    ~paddingRight="5%",
    ~width="15%",
    ~float="right",
    ~paddingTop="3px",
    (),
  );

let labelContainerStyle =
  ReactDOMRe.Style.make(
    ~paddingTop="3px",
    ~paddingLeft="5%",
    ~float="left",
    ~overflow="hidden",
    ~width="75%",
    ~whiteSpace="nowrap",
    ~textOverflow="ellipsis",
    ~margin="0",
    ~background="white",
    (),
  );

[@react.component]
let make =
    (
      ~selectedCountry,
      ~searchIsOpen,
      ~onClick,
      ~isLoading,
      ~tabIndex,
      ~selectActivatorRef,
    ) =>
  <div style onClick tabIndex ref=selectActivatorRef>
    <div style=labelContainerStyle>
      <span>
        {(
           switch (selectedCountry) {
           | None => ""
           | Some(c) => c.label
           }
         )
         |> s}
      </span>
    </div>
    <div style=styleIcoContainer>
      {isLoading ? <Loading /> : <ActivatorIcon active=searchIsOpen />}
    </div>
  </div>;
