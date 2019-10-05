// [@bs.as "type"] ~_type: '_type=?,

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
module Control = {
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
    "Control";
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
    ~value: Js.Nullable.t('jsOption),
    ~menuIsOpen: bool=?,
    ~onChange: 'option => unit=?,
    ~placeholder: 'placeholder=?,
    ~components: 'components=?,
    ~filterOption: 'filterOption=?
  ) =>
  React.element =
  "default";
