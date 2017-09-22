open Jest;

open ReasonThese;

let testFn = these (fun a => a + 1) (fun a => a + 2) (fun a b => a + b);

describe
  "ReasonThese"
  (
    fun () => {
      test
        "This-these"
        (fun () => Expect.expect (testFn (This 10)) |> Expect.toBe 11);
      test
        "That-these"
        (fun () => Expect.expect (testFn (That 10)) |> Expect.toBe 12);
      test
        "These-these"
        (fun () => Expect.expect (testFn (These 10 10)) |> Expect.toBe 20)
    }
  );
