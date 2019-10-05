open React;
let s = string;

let valueOfEvent = event => ReactEvent.Form.target(event)##value;
