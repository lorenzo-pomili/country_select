Utils.requireCss(
  "node_modules/@fortawesome/fontawesome-free/css/all.min.css",
);

let neutralStyle = ReactDOMRe.Style.make();

[@react.component]
let make = (~className, ~style=?) =>
  <span style={Belt.Option.getWithDefault(style, neutralStyle)} className />;
