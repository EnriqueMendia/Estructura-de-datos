object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 509
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 0
    Top = 8
    Width = 120
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 0
    Top = 48
    Width = 120
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 88
    Width = 120
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 128
    Width = 120
    Height = 25
    Caption = 'Crear Conjunto A'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 168
    Width = 120
    Height = 25
    Caption = 'Crear Conjunto B'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 0
    Top = 208
    Width = 120
    Height = 25
    Caption = 'Crear Conjunto C'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 50
    Width = 80
    Height = 23
    TabOrder = 6
    TextHint = 'x,y,z'
  end
  object Edit2: TEdit
    Left = 136
    Top = 90
    Width = 80
    Height = 23
    TabOrder = 7
    TextHint = 'dir...'
  end
  object Button7: TButton
    Left = 0
    Top = 248
    Width = 120
    Height = 25
    Caption = 'Poner Elemento'
    TabOrder = 8
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 0
    Top = 288
    Width = 120
    Height = 25
    Caption = 'Mostrar Conjunto'
    TabOrder = 9
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 0
    Top = 328
    Width = 120
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 10
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 0
    Top = 368
    Width = 120
    Height = 25
    Caption = 'Unir A,B en C'
    TabOrder = 11
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 0
    Top = 408
    Width = 120
    Height = 25
    Caption = 'Intersectar A,B en C'
    TabOrder = 12
    OnClick = Button11Click
  end
  object Edit3: TEdit
    Left = 136
    Top = 249
    Width = 80
    Height = 23
    TabOrder = 13
    TextHint = 'Conj...'
  end
  object Edit4: TEdit
    Left = 232
    Top = 249
    Width = 80
    Height = 23
    TabOrder = 14
    TextHint = 'elem...'
  end
  object Edit5: TEdit
    Left = 136
    Top = 289
    Width = 80
    Height = 23
    TabOrder = 15
    TextHint = 'Conj...'
  end
  object Button12: TButton
    Left = 0
    Top = 448
    Width = 120
    Height = 25
    Caption = 'Complemento Inter'
    TabOrder = 16
    OnClick = Button12Click
  end
end
