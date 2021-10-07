begin

Chuaxet[v]:=false;

For u ∈ Ke(v) do

If Chuaxet[u] then

Begin

T:=T  (u,v);

STREE_DFS(u);

End;

end;

(* Main Program *)

begin

(* Initialition *)

for u ∈ V do Chuaxet[u]:=true;

T := ∅ ; (* T la tap canh cua cay khung *)

STREE_DFS(root); ( root la dinh nao do cua do thi *)

end.