let xint _ = Scanf.scanf " %d" (fun x -> x)

let () = 
  let t = xint () in
  for cas = 1 to t do
    let n = xint () in
    let a = Array.make n 0 in
    for i = 0 to n - 1 do
      a.(i) <- xint ()
    done;
    Array.sort compare a;
    let r1 = ref 0 and r2 = ref 0 in
    let i = ref 0 in
    while !i < n do
      let j = ref !i in
      while !j + 1 < n && a.(!j) + 1 = a.(!j + 1) do
        j := !j + 1
      done;
      let c = !j - !i + 1 in
      r1 := !r1 + c / 3;
      if c mod 3 != 0 then r1 := !r1 + 1;
      r2 := !r2 + c / 2;
      if c mod 2 != 0 then r2 := !r2 + 1;
      i := !j + 1;
    done;
    Printf.printf "%d %d\n" !r1 !r2;
  done
