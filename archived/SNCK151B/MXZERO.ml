let xint _ = Scanf.scanf " %d" (fun x -> x)

let () =
  let t = xint () in
  for cas = 1 to t do
    let n = xint () in
    let c0 = ref 0 and c1 = ref 0 and r = ref 0 in
    for i = 1 to n do
      let x = xint () in
      r := !r lxor x;
      if x = 0 then c0 := !c0 + 1
      else c1 := !c1 + 1
    done;
    Printf.printf "%d\n" (
      if !r = 0 then !c0
      else !c1
    )
  done
