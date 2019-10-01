type countryId = string;

type t = {
  value: countryId,
  label: string,
};

let jsonDecoder = json =>
  Json.Decode.{
    label: json |> field("label", string),
    value: json |> field("value", string),
  };

let jsonArrayDecoder = (arrayJson: Js.Json.t): array(t) =>
  arrayJson |> Json.Decode.array(jsonDecoder);
