[@bs.val] external requireCss: string => unit = "require";

requireCss("node_modules/@fortawesome/fontawesome-free/css/all.min.css");

let style = ReactDOMRe.Style.make(~marginRight="10px", ());

[@react.component]
let make = () => <span style className="fas fa-search" />;
