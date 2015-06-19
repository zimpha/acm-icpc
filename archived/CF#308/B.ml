let xint _ = Scanf.scanf " %d" (fun x -> x)

let () =
  let n = xint() in
  if (n < 10) then print_int n
  else (
    let s = ref 9L in
    let p = ref 10 in
    let d = ref 2 in
    while !p <= n / 10 do
      s := Int64.add !s (Int64.mul (Int64.of_int !p) (Int64.of_int (9 * !d)));
      p := !p * 10;
      d := !d + 1;
    done;
    p := n - !p + 1;
    s := Int64.add !s (Int64.mul (Int64.of_int !p) (Int64.of_int !d));
    print_endline (Int64.to_string !s);
  )
