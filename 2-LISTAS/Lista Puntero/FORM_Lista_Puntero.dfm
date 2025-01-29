object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 441
  ClientWidth = 624
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 100
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 47
    Width = 100
    Height = 25
    Caption = 'Inserta Inicio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 88
    Width = 100
    Height = 25
    Caption = 'Inserta Final'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 128
    Width = 100
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 136
    Top = 48
    Width = 121
    Height = 23
    TabOrder = 4
    TextHint = 'elem...'
  end
  object Edit2: TEdit
    Left = 136
    Top = 89
    Width = 121
    Height = 23
    TabOrder = 5
    TextHint = 'elem...'
  end
end
