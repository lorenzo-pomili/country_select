let style = ReactDOMRe.Style.make(~float="right", ());

[@react.component]
let make = (~active) => {
  let className = "fas fa-caret-" ++ (active ? "up" : "down");
  <FontawesomeIcon style className />;
};
