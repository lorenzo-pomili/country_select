Utils.requireCss("./menu.css");
let style =
  ReactDOMRe.Style.make(~marginTop="0px", ~border="solid 2px red", ());

[@react.component]
let make = (~props) =>
  <div className="menuClass">
    <ReactSelect.Menu
      cx=props##cx
      clearValue=props##clearValue
      getStyles=props##getStyles
      getValue=props##getValue
      hasValue=props##hasValue
      isMulti=props##isMulti
      isRtl=props##isRtl
      options=props##options
      selectOption=props##selectOption
      setValue=props##setValue
      selectProps=props##selectProps
      theme=props##theme
      minMenuHeight=props##minMenuHeight
      maxMenuHeight=props##maxMenuHeight
      menuPlacement=props##menuPlacement
      menuPosition=props##menuPosition
      menuShouldScrollIntoView=props##menuShouldScrollIntoView
      innerRef=props##innerRef
      innerProps=props##innerProps
      isLoading=props##isLoading
      placement=props##placement>
      {props##children}
    </ReactSelect.Menu>
  </div>;
