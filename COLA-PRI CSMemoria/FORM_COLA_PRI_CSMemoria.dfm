object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 516
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button2: TButton
    Left = 0
    Top = 48
    Width = 120
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 0
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 88
    Width = 120
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 1
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 128
    Width = 120
    Height = 25
    Caption = 'Crear Cola1'
    TabOrder = 2
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 248
    Width = 120
    Height = 25
    Caption = 'Poner Cola1'
    TabOrder = 3
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 0
    Top = 327
    Width = 120
    Height = 25
    Caption = 'Mostrar Cola'
    TabOrder = 4
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 0
    Top = 447
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 5
  end
  object Button8: TButton
    Left = 0
    Top = 366
    Width = 120
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 6
    OnClick = Button8Click
  end
  object Button1: TButton
    Left = 0
    Top = 8
    Width = 120
    Height = 25
    Caption = 'Crear Memoria'
    TabOrder = 7
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 49
    Width = 100
    Height = 23
    TabOrder = 8
    TextHint = 'ej,em,plo'
  end
  object Edit2: TEdit
    Left = 136
    Top = 89
    Width = 100
    Height = 23
    TabOrder = 9
    TextHint = 'dir...'
  end
  object Edit3: TEdit
    Left = 136
    Top = 249
    Width = 100
    Height = 23
    TabOrder = 10
    TextHint = 'elem...'
  end
  object Button9: TButton
    Left = 0
    Top = 408
    Width = 120
    Height = 25
    Caption = 'Concatenar'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 0
    Top = 287
    Width = 120
    Height = 25
    Caption = 'Poner Cola2'
    TabOrder = 12
    OnClick = Button10Click
  end
  object Edit4: TEdit
    Left = 136
    Top = 288
    Width = 100
    Height = 23
    TabOrder = 13
    TextHint = 'elem...'
  end
  object Button11: TButton
    Left = 0
    Top = 168
    Width = 120
    Height = 25
    Caption = 'Crear Cola2'
    TabOrder = 14
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 0
    Top = 208
    Width = 120
    Height = 25
    Caption = 'Crear Cola3'
    TabOrder = 15
    OnClick = Button12Click
  end
end
