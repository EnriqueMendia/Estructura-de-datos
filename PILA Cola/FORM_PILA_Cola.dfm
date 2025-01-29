object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  CustomTitleBar.CaptionAlignment = taCenter
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  WindowState = wsMaximized
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
    Top = 47
    Width = 120
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 0
    Top = 86
    Width = 120
    Height = 25
    Caption = 'Crear Pila'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 0
    Top = 125
    Width = 120
    Height = 25
    Caption = 'Poner Pila'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 0
    Top = 164
    Width = 120
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 0
    Top = 203
    Width = 120
    Height = 25
    Caption = 'Mostrar Pila'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 0
    Top = 322
    Width = 120
    Height = 25
    Caption = 'Salir'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 48
    Width = 121
    Height = 23
    TabOrder = 7
    TextHint = 'ej,em,plo'
  end
  object Edit2: TEdit
    Left = 136
    Top = 126
    Width = 121
    Height = 23
    TabOrder = 8
    TextHint = 'elem...'
  end
  object Button8: TButton
    Left = 0
    Top = 240
    Width = 120
    Height = 25
    Caption = 'Infija a PostFija'
    TabOrder = 9
    OnClick = Button8Click
  end
  object Edit3: TEdit
    Left = 136
    Top = 241
    Width = 121
    Height = 23
    TabOrder = 10
    TextHint = 'Infija..'
  end
  object Button9: TButton
    Left = 0
    Top = 280
    Width = 120
    Height = 25
    Caption = 'Evalua PostFija'
    TabOrder = 11
    OnClick = Button9Click
  end
  object Edit4: TEdit
    Left = 136
    Top = 281
    Width = 121
    Height = 23
    TabOrder = 12
    TextHint = 'PostFija..'
  end
  object Button10: TButton
    Left = 0
    Top = 368
    Width = 120
    Height = 25
    Caption = 'SWAP'
    TabOrder = 13
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 0
    Top = 399
    Width = 120
    Height = 25
    Caption = 'ROTAR'
    TabOrder = 14
    OnClick = Button11Click
  end
  object Edit5: TEdit
    Left = 136
    Top = 369
    Width = 51
    Height = 23
    TabOrder = 15
    TextHint = 'Lug1'
  end
  object Edit6: TEdit
    Left = 206
    Top = 369
    Width = 51
    Height = 23
    TabOrder = 16
    TextHint = 'Lug2'
  end
  object Button12: TButton
    Left = 136
    Top = 86
    Width = 121
    Height = 25
    Caption = 'Crear Cola'
    TabOrder = 17
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 136
    Top = 164
    Width = 121
    Height = 25
    Caption = 'Poner Cola'
    TabOrder = 18
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 136
    Top = 203
    Width = 121
    Height = 25
    Caption = 'Mostrar Cola'
    TabOrder = 19
    OnClick = Button14Click
  end
end
