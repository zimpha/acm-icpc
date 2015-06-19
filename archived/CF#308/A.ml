let xint _ = Scanf.scanf " %d" (fun x -> x)

let () = 
  let n = xint () in
  let sum = ref 0 in
  for i = 1 to n do
    let x1 = xint () in
    let y1 = xint () in
    let x2 = xint () in
    let y2 = xint () in
    sum := !sum + (x2 - x1 + 1) * (y2 - y1 + 1);
  done;
  print_int !sum
