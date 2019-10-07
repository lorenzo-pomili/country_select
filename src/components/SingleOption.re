open Country;
open ReactUtils;

[@react.component]
let make = (~props) =>
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
      <> <Flag nationCode={props##data.value} /> {props##data.label |> s} </>
    </ReactSelect.Option>
  </div>;
