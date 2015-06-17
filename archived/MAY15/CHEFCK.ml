open Num;;
let xint _ = Scanf.scanf " %d" (fun x -> x);;
let xll () = Int64.of_int (xint ());;
let pm = 1000000007L;;

let mul x y m = Int64.rem (Int64.mul x y) m;;
let add x y m = Int64.rem (Int64.add x y) m;;
let min x y = if x < y then x else y;;

let () = 
  let n = xint () and k = xint () and q = xint () in
  let qa = Array.make (n + 1) pm and ms = Array.make (n + 1) pm and mp = Array.make (n + 1) pm in
  let a = xll () and b = xll () and c = xll () and d = xll () and e = xll () in
  let f = xll () and r = xll () and s = xll () and t = xll () and m = xll () in
  qa.(0) <- xll ();
  let l1 = ref (xll ()) and la = xll () and lc = xll () and lm = xll () in
  let d1 = ref (xll ()) and da = xll () and dc = xll () and dm = xll () in
  let pt = ref t in
  for i = 1 to n - 1 do
    pt := mul !pt t s;
    if !pt <= r then (
      qa.(i) <- add (mul (mul a qa.(i - 1) m) qa.(i - 1) m) (mul qa.(i - 1) b m) m;
      qa.(i) <- add qa.(i) c m;
    )
    else (
      qa.(i) <- add (mul (mul d qa.(i - 1) m) qa.(i - 1) m) (mul qa.(i - 1) e m) m;
      qa.(i) <- add qa.(i) f m;
    )
  done;
  for i = 0 to n - 1 do
    if i mod k = 0 then mp.(i) <- qa.(i)
    else mp.(i) <- min mp.(i - 1) qa.(i)
  done;
  for i = n - 1 downto 0 do
    if i mod k = k - 1 then ms.(i) <- qa.(i)
    else ms.(i) <- min ms.(i + 1) qa.(i)
  done;
  let sum = ref 0L and pro = ref 1L in
  for i = 1 to q do
    l1 := add (mul la !l1 lm) lc lm;
    d1 := add (mul da !d1 dm) dc dm;
    let ll = 1 + (Int64.to_int !l1) in
    let rr = min (ll + k - 1 + (Int64.to_int !d1)) n in
    let l = ll - 1 and r = rr - 1 in
    let pl = l / k and pr = r / k in

    let getmin x y =
      let r = ref qa.(x) in
      for i = x to y do
        r := min !r qa.(i)
      done;
      !r
    in
    let mx = (
      if pl = pr then mp.(r)
      else (
        if pl + 1 = pr then min mp.(r) ms.(l)
        else min mp.(r) (min ms.(l) mp.(k * pr - 1))
      )
    ) in
    sum := add !sum mx pm;
    pro := mul !pro mx pm;
  done;
  Printf.printf "%Ld %Ld\n" !sum !pro;