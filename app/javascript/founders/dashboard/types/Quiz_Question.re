type t = {
  id: int,
  question: string,
  description: option(string),
  correctAnswerId: int,
  answer_options: list(Quiz_Answer.t),
};

let decode = json =>
  Json.Decode.{
    id: json |> field("id", int),
    question: json |> field("question", string),
    description:
      json |> field("description", nullable(string)) |> Js.Null.toOption,
    correctAnswerId: json |> field("correct_answer_id", int),
    answer_options:
      json |> field("answer_options", list(Quiz_Answer.decode)),
  };

let id = t => t.id;

let question = t => t.question;

let description = t => t.description;

let correctAnswerId = t => t.correctAnswerId;

let answer_options = t => t.answer_options;