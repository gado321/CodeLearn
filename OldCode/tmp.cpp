f[0]:= 0;
f[1]:= c[1];
For i:=2 To L Do
Begin
Min:= Maxint;
For j:=1 To b Do
If i>= j Then
If f[i-j] + c[j]< Min Then
Begin
Min:= f[i-j] + c[j];
End;
f[i]:= Min;
End;
End;