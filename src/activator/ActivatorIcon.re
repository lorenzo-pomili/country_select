[@react.component]
let make = (~active) => {
  let className = "fas fa-caret-" ++ (active ? "up" : "down");
  <FontawesomeIcon className />;
};
