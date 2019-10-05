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
      ~menuIsOpen=?,
      ~filterOption,
    ) => {
  <div>
    <ReactSelect
      className
      options
      value={Js.Nullable.fromOption(selectedToJs(selectedOption))}
      menuIsOpen={menuIsOpen->Belt.Option.getWithDefault(false)}
      onChange
      placeholder={Js.Nullable.fromOption(placeholder)}
      components={
        "Option": elementOfOption,
        "IndicatorSeparator": indicatorSeparator,
        "DropdownIndicator": dropdownIndicator,
      }
      filterOption
    />
  </div>;
};
