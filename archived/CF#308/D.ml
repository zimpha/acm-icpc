let xint _ = Scanf.scanf " %d" (fun x -> x)

let () =
  let slope x y =
    if y == 0 then 1e12
    else (float_of_int x) /. (float_of_int y)
  in
  let n = xint () in
  if n <= 2 then (
    print_endline "0";
    exit 0;
  );
  let x = Array.make n 0 and y = Array.make n 0 in
  for i = 0 to n - 1 do
    x.(i) <- xint ();
    y.(i) <- xint ();
  done;
  let ret = ref 0l in
  for i = 0 to n - 1 do
    let v = Array.make (n - i - 1) 0.0 in
    for j = i + 1 to n - 1 do
      v.(j - i - 1) <- slope (y.(j) - y.(i)) (x.(j) - x.(i));
    done;
    Array.sort compare v;
    let cnt = ref 0 in
    for x = 1 to n - i - 2 do
      if v.(x) = v.(x - 1) then cnt := !cnt + 1
      else cnt := 0;
      ret := Int32.add !ret (Int32.of_int !cnt);
    done;
  done;
  let total = ref (Int64.of_int n) in
  total := Int64.mul !total (Int64.of_int (n - 1));
  total := Int64.mul !total (Int64.of_int (n - 2));
  total := Int64.div !total 6L;
  total := Int64.sub !total (Int64.of_int32 !ret);
  print_endline (Int64.to_string !total);
