let xint _ = Scanf.scanf " %d" (fun x -> x)

let () = 
  let t = xint () in
  for cas = 1 to t do
    let n = xint () and sum = ref 0 in
    let a = Array.make n 0 in
    for i = 0 to n - 1 do
      a.(i) <- xint ();
      sum := !sum + a.(i)
    done;
    Array.sort (fun x y -> x - y) a;
    Printf.printf "%d\n" (
      if a.(0) = 1 then ~-1
      else (
        if n = 1 then 2
        else !sum - a.(0) + 2
      )
    )
  done
