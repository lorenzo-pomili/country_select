[@react.component]
let make =
    (
      ~className,
      ~options,
      ~selectedOption,
      ~selectedToJs,
      ~onChange,
      ~elementOfOption,
      ~placeholder=?,
      ~indicatorSeparator=?,
      ~dropdownIndicator=?,
      ~input=?,
      ~isClearable,
      ~isSearchable,
      ~menuIsOpen=?,
      ~filterOption=?,
    ) =>
  <ReactSelect
    className
    options
    value={Js.Nullable.fromOption(selectedToJs(selectedOption))}
    menuIsOpen={menuIsOpen->Belt.Option.getWithDefault(false)}
    onChange
    isClearable
    isSearchable
    placeholder={Js.Nullable.fromOption(placeholder)}
    components={
      "Option": elementOfOption,
      "IndicatorSeparator": indicatorSeparator,
      "DropdownIndicator": dropdownIndicator,
      "Input": input,
    }
    filterOption
  />;
