     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
     .align    2         
     .globl    whilefalse
     .set      nomips16  
     .set      nomicromips
     .ent      whilefalse
     .type     whilefalse,@function
$LFB0= .
whilefalse:
     .frame    $fp,16,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-16
     sw        $fp,12($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     li          $2,6
     sw          $2,4($fp)
     sw          $0,8($fp)
$L3:
     lw          $2,4($fp)
     li          $3,6
     beq         $2,$3,$L2
     nop       

     li          $2,1
     b          $L4
     nop       

     b          $L3
     nop       

 $L2:
     move        $2,$0
     b          $L4
     nop       

$L4:
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $fp,12($sp)
     addiu     $sp,$sp,16
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      whilefalse
     .size     whilefalse, .-whilefalse
