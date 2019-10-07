open ReactUtils;

[@react.component]
let make = (~props) => {
  <div>
    <span>
      <ReactSelect.Input
        autoCapitalize=props##autoCapitalize
        autoComplete=props##autoComplete
        autoCorrect=props##autoCorrect
        cx=props##cx
        getStyles=props##getStyles
        id=props##id
        innerRef=props##innerRef
        isDisabled=props##isDisabled
        isHidden=props##isHidden
        onBlur=props##onBlur
        onChange=props##onChange
        onFocus={e => {
          Js.log(e);
          Js.log(props##onFocus);
          props##onFocus;
        }}
        selectProps=props##selectProps
        spellCheck=props##spellCheck
        tabIndex=props##tabIndex
        theme=props##theme
        value=props##value
        type_=props##"type"
      />
    </span>
  </div>;
};
