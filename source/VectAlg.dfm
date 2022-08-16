object VectAlgFm: TVectAlgFm
  Left = 8
  Top = 109
  Width = 620
  Height = 539
  Caption = 'Отладка векторных велечин'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 16
    Width = 79
    Height = 20
    Caption = 'Вектор А'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 144
    Width = 94
    Height = 20
    Caption = 'Сумма А+В'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 8
    Top = 185
    Width = 138
    Height = 20
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Caption = 'Умножение А на'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
  end
  object Label2: TLabel
    Left = 32
    Top = 56
    Width = 79
    Height = 20
    Caption = 'Вектор В'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object StaticText1: TStaticText
    Left = 16
    Top = 248
    Width = 129
    Height = 49
    Alignment = taCenter
    AutoSize = False
    Caption = 'Скалярное произведение'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
  end
  object StaticText2: TStaticText
    Left = 16
    Top = 320
    Width = 137
    Height = 41
    Alignment = taCenter
    AutoSize = False
    Caption = 'Векторное произведение'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
  end
  object Ax: TMaskEdit
    Left = 178
    Top = 17
    Width = 97
    Height = 21
    TabOrder = 2
  end
  object Ay: TMaskEdit
    Left = 279
    Top = 17
    Width = 97
    Height = 21
    TabOrder = 3
  end
  object Az: TMaskEdit
    Left = 381
    Top = 17
    Width = 97
    Height = 21
    TabOrder = 4
  end
  object ModylA: TMaskEdit
    Left = 482
    Top = 17
    Width = 97
    Height = 21
    TabOrder = 5
  end
  object Bx: TMaskEdit
    Left = 178
    Top = 57
    Width = 97
    Height = 21
    TabOrder = 6
  end
  object By: TMaskEdit
    Left = 279
    Top = 57
    Width = 97
    Height = 21
    TabOrder = 7
  end
  object Bz: TMaskEdit
    Left = 381
    Top = 57
    Width = 97
    Height = 21
    TabOrder = 8
  end
  object ModylB: TMaskEdit
    Left = 482
    Top = 57
    Width = 97
    Height = 21
    TabOrder = 9
  end
  object CalcBitBtn: TBitBtn
    Left = 272
    Top = 456
    Width = 105
    Height = 25
    Caption = 'Вычислить'
    TabOrder = 10
    OnClick = CalcBitBtnClick
  end
  object ABx: TMaskEdit
    Left = 176
    Top = 136
    Width = 97
    Height = 21
    TabOrder = 11
    Text = 'ABx'
  end
  object ABy: TMaskEdit
    Left = 280
    Top = 136
    Width = 97
    Height = 21
    TabOrder = 12
    Text = 'ABy'
  end
  object ABz: TMaskEdit
    Left = 384
    Top = 136
    Width = 97
    Height = 21
    TabOrder = 13
    Text = 'ABz'
  end
  object ModylAB: TMaskEdit
    Left = 488
    Top = 136
    Width = 89
    Height = 21
    TabOrder = 14
    Text = 'ModylAB'
  end
  object N: TMaskEdit
    Left = 64
    Top = 208
    Width = 33
    Height = 21
    TabOrder = 15
    Text = 'N'
  end
  object ANx: TMaskEdit
    Left = 176
    Top = 200
    Width = 97
    Height = 21
    TabOrder = 16
    Text = 'ANx'
  end
  object ANy: TMaskEdit
    Left = 280
    Top = 200
    Width = 97
    Height = 21
    TabOrder = 17
    Text = 'ANy'
  end
  object ANz: TMaskEdit
    Left = 384
    Top = 200
    Width = 97
    Height = 21
    TabOrder = 18
    Text = 'ANz'
  end
  object ModylAN: TMaskEdit
    Left = 488
    Top = 200
    Width = 89
    Height = 21
    TabOrder = 19
    Text = 'ModylAN'
  end
  object PrABx: TMaskEdit
    Left = 312
    Top = 256
    Width = 113
    Height = 21
    TabOrder = 20
    Text = 'PrABx'
  end
  object VABx: TMaskEdit
    Left = 176
    Top = 320
    Width = 97
    Height = 21
    TabOrder = 21
    Text = 'VABx'
  end
  object VABy: TMaskEdit
    Left = 280
    Top = 320
    Width = 97
    Height = 21
    TabOrder = 22
    Text = 'VABy'
  end
  object VABz: TMaskEdit
    Left = 384
    Top = 320
    Width = 97
    Height = 21
    TabOrder = 23
    Text = 'VABz'
  end
  object ModylVAB: TMaskEdit
    Left = 488
    Top = 320
    Width = 89
    Height = 21
    TabOrder = 24
    Text = 'ModylVAB'
  end
  object StaticText3: TStaticText
    Left = 24
    Top = 96
    Width = 89
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'Вектор С'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 25
  end
  object Cx: TMaskEdit
    Left = 178
    Top = 97
    Width = 97
    Height = 21
    TabOrder = 26
  end
  object Cy: TMaskEdit
    Left = 279
    Top = 97
    Width = 97
    Height = 21
    TabOrder = 27
  end
  object Cz: TMaskEdit
    Left = 381
    Top = 97
    Width = 97
    Height = 21
    TabOrder = 28
  end
  object ModulC: TMaskEdit
    Left = 482
    Top = 97
    Width = 97
    Height = 21
    TabOrder = 29
  end
  object StaticText4: TStaticText
    Left = 16
    Top = 376
    Width = 137
    Height = 65
    Alignment = taCenter
    AutoSize = False
    Caption = 'Векторное произведение A*B*C'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 30
  end
  object VABCx: TMaskEdit
    Left = 176
    Top = 392
    Width = 97
    Height = 21
    TabOrder = 31
    Text = 'VABx'
  end
  object VABCy: TMaskEdit
    Left = 280
    Top = 392
    Width = 97
    Height = 21
    TabOrder = 32
    Text = 'VABy'
  end
  object VABCz: TMaskEdit
    Left = 384
    Top = 392
    Width = 97
    Height = 21
    TabOrder = 33
    Text = 'VABz'
  end
  object ModulABC: TMaskEdit
    Left = 488
    Top = 392
    Width = 89
    Height = 21
    TabOrder = 34
    Text = 'ModylVAB'
  end
end
