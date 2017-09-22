type these 'a 'b =
  | This 'a
  | That 'b
  | These 'a 'b;

let these f g h these =>
  switch these {
  | This a => f a
  | That b => g b
  | These a b => h a b
  };

let identity a => a;

let mapBoth f g =>
  these
    (fun a => This (f a)) (fun b => That (g b)) (fun a b => These (f a) (g b));

let mapThis f => mapBoth f identity;

let mapThat f => mapBoth identity f;

let merge f => these identity identity f;

let mergeWith f g h => these g h (fun x y => f (g x) (h y));

let rec align' acc xss yss =>
  switch (xss, yss) {
  | ([], []) => List.rev acc
  | ([x, ...xs], []) => align' [This x, ...acc] xs []
  | ([], [y, ...ys]) => align' [That y, ...acc] [] ys
  | ([x, ...xs], [y, ...ys]) => align' [These x y, ...acc] xs ys
  };

let align a b => align' [] a b;
