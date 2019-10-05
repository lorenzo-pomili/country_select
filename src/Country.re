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

let jsonEncode = r =>
  Json.Encode.(
    object_([("value", r.value |> string), ("label", r.label |> string)])
  );

let jsonArrayEconder = (arrayRecords: array(t)) =>
  arrayRecords |> Json.Encode.array(jsonEncode);
