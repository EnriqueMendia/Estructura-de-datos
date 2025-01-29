object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 445
  ClientWidth = 727
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 100
    Height = 25
    Caption = 'Crear SM'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 48
    Width = 100
    Height = 25
    Caption = 'Pedir Espacio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 88
    Width = 100
    Height = 25
    Caption = 'Liberar Espacio'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 128
    Width = 100
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 168
    Width = 100
    Height = 25
    Caption = 'Insertar Inicio'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 8
    Top = 209
    Width = 100
    Height = 25
    Caption = 'Insertar Final'
    TabOrder = 5
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 8
    Top = 248
    Width = 100
    Height = 25
    Caption = 'Mostrar Memoria'
    TabOrder = 6
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 8
    Top = 288
    Width = 100
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 7
    OnClick = Button8Click
  end
  object Edit1: TEdit
    Left = 152
    Top = 50
    Width = 121
    Height = 21
    TabOrder = 8
    TextHint = 'Eje,mp,lo'
  end
  object Edit2: TEdit
    Left = 152
    Top = 90
    Width = 121
    Height = 21
    TabOrder = 9
    TextHint = 'dir...'
  end
  object Edit3: TEdit
    Left = 152
    Top = 170
    Width = 121
    Height = 21
    TabOrder = 10
    TextHint = 'elem...'
  end
  object Edit4: TEdit
    Left = 152
    Top = 211
    Width = 121
    Height = 21
    TabOrder = 11
    TextHint = 'elem...'
  end
end
