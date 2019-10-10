open React;
let s = string;

let valueOfEvent = event => ReactEvent.Form.target(event)##value;

let keyOfEvent = event => ReactEvent.Keyboard.key(event);
