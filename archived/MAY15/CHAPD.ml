open Num;;
let xint () = Scanf.scanf " %d" (fun x -> x)
let xll () = Scanf.scanf " %Ld" (fun x -> x)

let () = 
  let rec check x y =
    let rec gcd x y = 
      if y = 0L then x
      else gcd y (Int64.rem x y)
    in
    let g = gcd x y in
    if g = 1L then y = 1L
    else check x (Int64.div y g)
  in
  let ncas = xint () in
  for cas = 1 to ncas do
    let a = xll () and b = xll () in
    print_endline (if check a b then "Yes" else "No")
  done
