[@react.component]
let make =
    (
      ~className,
      ~options,
      ~selectedOption,
      ~selectedToJs,
      ~onChange,
      ~elementOfOption,
      ~indicatorSeparator=?,
      ~dropdownIndicator=?,
      ~menuIsOpen=?,
      ~filterOption,
    ) => {
  Js.log2("selectedOption: ", selectedOption);

  <div>
    <ReactSelect
      className
      options
      value={Js.Nullable.fromOption(selectedToJs(selectedOption))}
      menuIsOpen={menuIsOpen->Belt.Option.getWithDefault(false)}
      onChange
      components={
        "Option": elementOfOption,
        "IndicatorSeparator": indicatorSeparator,
        "DropdownIndicator": dropdownIndicator,
      }
      filterOption
    />
  </div>;
};
