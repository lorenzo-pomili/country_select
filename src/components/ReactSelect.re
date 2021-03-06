module Option = {
  [@bs.module "react-select"]
  [@bs.scope "components"]
  [@bs.val]
  [@react.component]
  external make:
    (
      ~cx: 'cx=?,
      ~clearValue: unit => unit,
      ~theme: 'theme,
      ~getStyles: 'getStyles,
      ~getValue: 'getValue,
      ~hasValue: 'hasValue,
      ~options: array('option)=?,
      ~setValue: 'setValue=?,
      ~selectOption: 'selectOption=?,
      ~isFocused: bool=?,
      ~isMulti: bool=?,
      ~isRtl: bool=?,
      ~isDisabled: bool=?,
      ~isSelected: bool=?,
      ~selectProps: 'selectProps=?,
      ~innerProps: 'innerProps=?,
      ~data: 'data=?,
      ~label: 'label=?,
      ~value: 'value=?,
      ~innerRef: 'innerRef=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Option";
};

module NoOptionsMessage = {
  [@bs.module "react-select"]
  [@bs.scope "components"]
  [@bs.val]
  [@react.component]
  external make:
    (
      ~cx: 'cx=?,
      ~clearValue: 'clearValue=?,
      ~getStyles: 'getStyles=?,
      ~getValue: 'getValue=?,
      ~hasValue: 'hasValue=?,
      ~isMulti: 'isMulti=?,
      ~isRtl: 'isRtl=?,
      ~options: 'options=?,
      ~selectOption: 'selectOption=?,
      ~setValue: 'setValue=?,
      ~selectProps: 'selectProps=?,
      ~theme: 'theme=?,
      ~children: React.element=?
    ) =>
    React.element =
    "NoOptionsMessage";
};

module Input = {
  [@bs.module "react-select"]
  [@bs.scope "components"]
  [@bs.val]
  [@react.component]
  external make:
    (
      ~autoCapitalize: 'autoCapitalize=?,
      ~autoComplete: 'autoComplete=?,
      ~autoCorrect: 'autoCorrect=?,
      ~cx: 'cx=?,
      ~getStyles: 'getStyles=?,
      ~id: 'id=?,
      ~innerRef: 'innerRef=?,
      ~isDisabled: 'isDisabled=?,
      ~isHidden: 'isHidden=?,
      ~onBlur: 'onBlur=?,
      ~onChange: 'onChange=?,
      ~onFocus: 'onFocus=?,
      ~selectProps: 'selectProps=?,
      ~spellCheck: 'spellCheck=?,
      ~tabIndex: 'tabIndex=?,
      ~theme: 'theme=?,
      ~value: 'value=?,
      ~type_: 'type_=?,
      ~ariaAutocomplete: 'ariaAutocomplete=?,
      ~ariaLabel: 'ariaLabel=?,
      ~ariaLabelledby: 'ariaLabelledby=?
    ) =>
    React.element =
    "Input";
};

module Menu = {
  [@bs.module "react-select"]
  [@bs.scope "components"]
  [@bs.val]
  [@react.component]
  external make:
    (
      ~cx: 'cx=?,
      ~clearValue: 'clearValue=?,
      ~getStyles: 'getStyles=?,
      ~getValue: 'getValue=?,
      ~hasValue: 'hasValue=?,
      ~isMulti: 'isMulti=?,
      ~isRtl: 'isRtl=?,
      ~options: 'options=?,
      ~selectOption: 'selectOption=?,
      ~setValue: 'setValue=?,
      ~selectProps: 'selectProps=?,
      ~theme: 'theme=?,
      ~minMenuHeight: 'minMenuHeight=?,
      ~maxMenuHeight: 'maxMenuHeight=?,
      ~menuPlacement: 'menuPlacement=?,
      ~menuPosition: 'menuPosition=?,
      ~menuShouldScrollIntoView: 'menuShouldScrollIntoView=?,
      ~innerRef: 'innerRef=?,
      ~innerProps: 'innerProps=?,
      ~isLoading: 'isLoading=?,
      ~placement: 'placement=?,
      ~children: React.element=?
    ) =>
    React.element =
    "Menu";
};

module DropdownIndicator = {
  [@bs.module "react-select"]
  [@bs.scope "components"]
  [@bs.val]
  [@react.component]
  external make:
    (
      ~cx: 'cx,
      ~theme: 'theme,
      ~getStyles: 'getStyles,
      ~children: React.element=?
    ) =>
    React.element =
    "DropdownIndicator";
};

[@bs.module "react-select"] [@react.component]
external make:
  (
    ~className: string=?,
    ~options: array('option)=?,
    ~value: Js.Nullable.t('jsOption)=?,
    ~isSearchable: bool=?,
    ~isClearable: bool=?,
    ~clearValue: 'clearValue=?,
    ~menuIsOpen: bool=?,
    ~onChange: Js.Nullable.t('option) => unit=?,
    ~placeholder: 'placeholder=?,
    ~components: 'components=?,
    ~filterOption: 'filterOption=?
  ) =>
  React.element =
  "default";
