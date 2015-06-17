open Num;;
let sin = Stream.of_channel stdin;;
let xint () =
  let rec next_int n =
    match Stream.next sin with
    | ' ' -> n
    | '\n' -> n
    | '-' -> -1 * (next_int 0)
    | c -> next_int (10 * n + (int_of_char c) - 48)
  in
  next_int 0
;;

let mm = 1000000007L and inv = 500000004L;;

let mul x y = Int64.rem (Int64.mul x y) mm;;
let add x y = Int64.rem (Int64.add x y) mm;;
let sub x y = add (Int64.rem (Int64.sub x y) mm) mm;;

let () = 
  let pw = Array.make 100010 1L in
  let rv = Array.make 100010 1L in
  for i = 1 to 100009 do
    pw.(i) <- mul 2L pw.(i - 1);
    rv.(i) <- mul inv rv.(i - 1)
  done;
  let ncas = xint () in
  for cas = 1 to ncas do
    let n = xint () in
    let a = Array.make (n + 1) 0L in
    for i = 1 to n do
      a.(i) <- Int64.of_int (xint ())
    done;
    Array.sort (fun x y -> Int64.to_int (Int64.sub x y)) a;
    let ret = ref 0L and s1 = ref 0L and s2 = ref 0L in
    for i = 1 to n do
      let x = mul !s1 (mul a.(i) pw.(i - 1)) in
      let y = mul pw.(i - 1) !s2 in
      ret := add !ret (sub x y);
      s1 := add !s1 rv.(i);
      s2 := add !s2 (mul rv.(i) a.(i))
    done;
    Printf.printf "%Ld\n" !ret
  done
