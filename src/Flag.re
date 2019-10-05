[@bs.val] external requireCss: string => unit = "require";

requireCss("node_modules/flag-icon-css/css/flag-icon.min.css");

let style = ReactDOMRe.Style.make(~marginRight="10px", ());

[@react.component]
let make = (~nationCode: string) =>
  <span
    className={"flag-icon-squared flag-icon flag-icon-" ++ nationCode}
    style
  />;
