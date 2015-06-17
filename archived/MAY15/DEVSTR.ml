let xint _ = Scanf.scanf " %d" (fun x -> x)
let xstr _ = Scanf.scanf " %s" (fun x -> x)

let () = 
  let rev x = if x = '0' then '1' else '0' in
  let ncas = xint () in
  for cas = 1 to ncas do
    let n = xint () and k = xint () and s = xstr () in
    let n = String.length s in
    if k = 1 then (
      let c1 = ref 0 and c2 = ref 0 in
      for i = 0 to n - 1 do
        if i mod 2 = 0 then (
          if s.[i] = '0' then c2 := !c2 + 1
          else c1 := !c1 + 1
        )
        else (
          if s.[i] = '1' then c2 := !c2 + 1
          else c1 := !c1 + 1
        )
      done;
      if !c1 > !c2 then (
        Printf.printf "%d\n" !c2;
        for i = 0 to n - 1 do
          if i mod 2 = 0 then print_char '1'
          else print_char '0'
        done;
        print_newline ()
      )
      else (
        Printf.printf "%d\n" !c1;
        for i = 0 to n - 1 do
          if i mod 2 = 1 then print_char '1'
          else print_char '0'
        done;
        print_newline ()
      )
    )
    else (
      let ret = ref 0 and i = ref 0 in
      while !i < n do
        let j = ref !i and c = rev s.[!i] in
        while !j < n && s.[!j] = s.[!i] do
          j := !j + 1
        done;
        let len = !j - !i in
        if len >= k + 1 then (
          let cnt = len / (k + 1) in
          ret := !ret + cnt;
          if len mod (k + 1) = 0 then (
            for x = 1 to cnt do
              s.[!i + x * (k + 1) - 2] <- c
            done
          )
          else (
            for x = 1 to cnt do
              s.[!i + x * (k + 1) - 1] <- c
            done;
          )
        );
        i := !j
      done;
      Printf.printf "%d\n%s\n" !ret s;
    )
  done
