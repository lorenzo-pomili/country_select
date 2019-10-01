open ReactUtils;
[@react.component]
let make = (~className, ~options, ~selectedOption, ~onChange, ~stringOfOption) =>
  <div>
    {options
     ->Belt.Array.mapWithIndex((i, op) =>
         <div key={string_of_int(i)}>
           {switch (selectedOption) {
            | Some(c) when c == op => <span> {s("=>")} </span>
            | None
            | Some(_) => React.null
            }}
           <span onClick={_e => onChange(op)}>
             {s(stringOfOption(op))}
           </span>
         </div>
       )
     ->React.array}
  </div>;
