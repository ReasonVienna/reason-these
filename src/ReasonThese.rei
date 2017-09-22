type these 'a 'b =
  | This 'a
  | That 'b
  | These 'a 'b;

let these: ('a => 'c) => ('b => 'c) => ('a => 'b => 'c) => these 'a 'b => 'c;

let identity: 'a => 'a;

let mapThis: ('a => 'c) => these 'a 'b => these 'c 'b;

let mapThat: ('b => 'c) => these 'a 'b => these 'a 'c;

let mapBoth: ('a => 'c) => ('b => 'd) => these 'a 'b => these 'c 'd;

let merge: ('a => 'a => 'a) => these 'a 'a => 'a;

let mergeWith:
  ('c => 'c => 'c) => ('a => 'c) => ('b => 'c) => these 'a 'b => 'c;

let align: list 'a => list 'b => list (these 'a 'b);
