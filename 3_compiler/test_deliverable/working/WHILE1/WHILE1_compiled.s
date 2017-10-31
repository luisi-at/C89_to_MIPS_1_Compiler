     .file     1 "file"       
     .section  .mdebug.abi32  
     .previous 
     .nan      legacy         
     .module   fp=xx          
     .module   nooddspreg     
     .abicalls 
     .text     
$LFB0= .       
     .align    2         
     .globl    whiletrue 
     .set      nomips16  
     .set      nomicromips
     .ent      whiletrue 
     .type     whiletrue, @function
whiletrue:
     .frame    $fp,20,$31
     .mask     0x40000000,-4
     .fmask    0x00000000,0
     .set      noreorder
     .set      nomacro
     addiu     $sp,$sp,-20
     sw        $31,16($sp)
     sw        $fp,12($sp)
     move      $fp,$sp
#====== ASSEMBLY COMING ======
     sw          $0,4($fp)
     sw          $0,8($fp)
$L3:
     lw          $2,4($fp)
     slt         $2,$2,1
     beq         $2,$0,$L2
     nop       

     lw         $2,4($fp)
     addiu     $2,$2,1
     sw         $2,4($fp)
     move        $2,$0
     b          $L4
     nop       

     b          $L3
     nop       

 $L2:
     li          $2,1
     b          $L4
     nop       

$L4:
#====== ASSEMBLY ENDING ======
     move      $sp,$fp
     lw        $31,16($sp)
     lw        $fp,12($sp)
     addiu     $sp,$sp,20
     j         $31 
     nop       
     .set      macro     
     .set      reorder   
     .end      whiletrue 
     .size     whiletrue, .-whiletrue
