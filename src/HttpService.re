open Js.Promise;
let get = (url, decoder) =>
  Fetch.fetch(url)
  |> then_(Fetch.Response.json)
  |> then_(json => decoder(json) |> resolve);
