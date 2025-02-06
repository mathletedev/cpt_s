{ pkgs ? import <nixpkgs> { } }:

let
  texlive = pkgs.texliveBasic.withPackages (ps: with ps; [
    enumitem
  ]);
in
pkgs.mkShell {
  buildInputs = with pkgs; [
    tex-fmt
    texlab
    texlive
  ];
}
