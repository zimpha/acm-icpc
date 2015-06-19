let xint _ = Scanf.scanf " %d" (fun x -> x)

let () = 
  let w = xint () and m = ref (xint ()) in
  while !m > 0 do
    let x = !m mod w in
    if x == 0 then m := !m / w
    else if x == 1 then m := !m - 1
    else if x == w - 1 then m := !m + 1
    else (
      print_endline "NO";
      exit 0;
    )
  done;
  print_endline "YES";
