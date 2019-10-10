[@react.component]
let make = (~props, ~children=?) =>
  <ReactSelect.NoOptionsMessage
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
    theme=props##theme>
    {children->Belt.Option.getWithDefault(React.null)}
  </ReactSelect.NoOptionsMessage>;
