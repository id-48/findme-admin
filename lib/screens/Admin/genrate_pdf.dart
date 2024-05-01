import 'dart:io';

import 'package:flutter/cupertino.dart';
import 'package:flutter/services.dart';
import 'package:intl/intl.dart';
import 'package:path_provider/path_provider.dart';
import 'package:pdf/pdf.dart';
import 'package:pdf/widgets.dart';
import 'package:printing/printing.dart';
import 'package:find_me_admin/utils/Constants.dart';
import 'package:syncfusion_flutter_pdf/pdf.dart';
import 'package:pdf/widgets.dart' as pw;

import '../../models/billing/get_billing/res_billing_data.dart';
import '../../utils/Colors.dart';

class PdfGeneratorView {
  Future<Uint8List> generateInvoice(// List<customerDetails> companyDetails,
      Billing billingData) async {
    List lstNetImg = [];
    for (int i = 0; i < billingData.billingData.length; i++) {
      final netImage = await networkImage(
          mBaseUrl + "${billingData.billingData[i].image}");
      lstNetImg.add(netImage);
    }
    final pdf = pw.Document();

    final img = await rootBundle.load("assets/app_logo_primary.png");

    final imageBytes = img.buffer.asUint8List();
    pw.Image image1 = pw.Image(pw.MemoryImage(imageBytes));
    int no = 0;
    pdf.addPage(pw.MultiPage(
        pageFormat: PdfPageFormat.a4,
        build: (pw.Context context) {
          return [
            pw.Column(children: [
              pw.Divider(color: PdfColors.black, thickness: 5),
              pw.Row(mainAxisAlignment: pw.MainAxisAlignment.start, children: [
                pw.Container(
                  width: 300,
                  child: pw.Column(
                      mainAxisAlignment: pw.MainAxisAlignment.start,
                      crossAxisAlignment: pw.CrossAxisAlignment.start,
                      children: [
                        pw.Row(children: [
                          pw.Text('BRANCH : ', style: pw.TextStyle(
                              fontSize: 10, fontWeight: FontWeight.bold)),
                          pw.Text(billingData.branchName),
                        ]),
                        pw.SizedBox(height: 10),
                        pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                            .spaceBetween, children: [
                          pw.Row(children: [
                            pw.Text('BILL NO : ', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text(billingData.billNo),
                          ]),
                          pw.SizedBox(width: 10),
                          pw.Row(children: [
                            pw.Text('BILLING DATE : ', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text(billingData.billingDate),
                          ])
                        ]),
                        pw.SizedBox(height: 10),
                        pw.Row(children: [
                          pw.Text('NAME : ', style: pw.TextStyle(
                              fontSize: 10, fontWeight: FontWeight.bold)),
                          pw.Text(billingData.name),
                        ]),
                        pw.SizedBox(height: 10),
                        pw.Row(children: [
                          pw.Text('ADDRESS : ', style: pw.TextStyle(
                              fontSize: 10, fontWeight: FontWeight.bold)),
                          pw.Text(billingData.address),
                        ]),
                        pw.SizedBox(height: 10),
                        pw.Row(children: [
                          pw.Text('MOBILE NO : ', style: pw.TextStyle(
                              fontSize: 10, fontWeight: FontWeight.bold)),
                          pw.Text(billingData.mobileNo),
                        ]),
                        pw.SizedBox(height: 10),
                        pw.Row(children: [
                          pw.Row(children: [
                            pw.Text('DELIVERY DATE : ', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text(billingData.deliveryDate),
                          ]),
                          pw.SizedBox(width: 10),
                          pw.Row(children: [
                            pw.Text('INSTRUCTION : ', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text(billingData.instruction),
                          ]),
                        ]),
                      ]),
                ),
                pw.SizedBox(width: 10),
                pw.Container(
                  alignment: pw.Alignment.center,
                  height: 200,
                  width: 200,
                  child: image1,
                )
              ]),
              pw.Divider(color: PdfColors.black, thickness: 2),
              pw.Container(
                  decoration: pw.BoxDecoration(color: PdfColors.blue50),
                  child: pw.Padding(
                      padding: pw.EdgeInsets.all(10),
                      child: pw.Row(
                          mainAxisAlignment: pw.MainAxisAlignment.spaceBetween,
                          children: [
                            pw.Text('SR.NO', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('MODEL NO', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('IMAGE', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('INSTRUCTION', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('DETAILS', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('QTY', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('PRICE', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                            pw.Text('TOTAL', style: pw.TextStyle(
                                fontSize: 10, fontWeight: FontWeight.bold)),
                          ]))),
              pw.Divider(
                color: PdfColors.black,
              ),
              pw.Wrap(
                  spacing: 00,
                  runSpacing: 10,
                  children: billingData.billingData.map((billingDetails) {
                    no++;
                    return pw.Container(
                        child: pw.Column(children: [
                          pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                              .spaceAround, children: [
                            pw.SizedBox(width: 5),
                            pw.Text('${no}', style: pw.TextStyle(fontSize: 10)),
                            pw.SizedBox(width: 5),
                            pw.Text(billingDetails.modelNumber,
                                style: pw.TextStyle(fontSize: 10)),
                            pw.SizedBox(width: 5),
                            pw.Container(
                              color: PdfColors.red600,
                              alignment: pw.Alignment.center,
                              height: 70,
                              width: 70,
                              child: pw.Image(
                                  lstNetImg[no - 1], fit: pw.BoxFit.fill),
                            ),
                            pw.SizedBox(width: 10),
                            pw.Column(
                                mainAxisAlignment: pw.MainAxisAlignment.start,
                                crossAxisAlignment: pw.CrossAxisAlignment.start,
                                children: [
                                  pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                                      .spaceAround, children: [
                                    pw.Text("COLOUR", style: pw.TextStyle(
                                        fontSize: 8,
                                        fontWeight: FontWeight.bold)),
                                    pw.SizedBox(width: 40),
                                    pw.Text("${billingDetails.colorSelect}",
                                        style: pw.TextStyle(
                                          fontSize: 8,
                                        )),
                                  ]),
                                  pw.SizedBox(height: 5),
                                  pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                                      .spaceBetween, children: [
                                    pw.Text("DESIGN", style: pw.TextStyle(
                                        fontSize: 8,
                                        fontWeight: FontWeight.bold)),
                                    pw.SizedBox(width: 45),
                                    pw.Text("${billingDetails.designSelect}",
                                        style: pw.TextStyle(
                                          fontSize: 8,
                                        )),
                                  ]),
                                  pw.SizedBox(height: 5),
                                  pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                                      .spaceBetween, children: [
                                    pw.Text("JACK & BASE ", style: pw.TextStyle(
                                        fontSize: 8,
                                        fontWeight: FontWeight.bold)),
                                    pw.SizedBox(width: 20),
                                    pw.Text(
                                        "${billingDetails.jackAndBaseSelect}",
                                        style: pw.TextStyle(
                                          fontSize: 8,
                                        )),
                                  ]),
                                  pw.SizedBox(height: 5),
                                  pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                                      .spaceBetween, children: [
                                    pw.Text("FOOTREST", style: pw.TextStyle(
                                        fontSize: 8,
                                        fontWeight: FontWeight.bold)),
                                    pw.SizedBox(width: 35),
                                    pw.Text("${billingDetails.footrestSelect}",
                                        style: pw.TextStyle(
                                          fontSize: 8,
                                        )),
                                  ]),
                                  pw.SizedBox(height: 5),
                                  pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                                      .spaceBetween, children: [
                                    pw.Text("OTHER", style: pw.TextStyle(
                                        fontSize: 8,
                                        fontWeight: FontWeight.bold)),
                                    pw.SizedBox(width: 40),
                                    pw.Text("${billingDetails.others1}",
                                        style: pw.TextStyle(
                                          fontSize: 8,
                                        )),
                                  ]),
                                  pw.SizedBox(height: 5),
                                  pw.Row(mainAxisAlignment: pw.MainAxisAlignment
                                      .spaceBetween, children: [
                                    pw.Text("OTHER", style: pw.TextStyle(
                                        fontSize: 8,
                                        fontWeight: FontWeight.bold)),
                                    pw.SizedBox(width: 40),
                                    pw.Text("${billingDetails.others2}",
                                        style: pw.TextStyle(
                                          fontSize: 8,
                                        )),
                                  ]),
                                  pw.SizedBox(height: 5),
                                ]),
                            pw.SizedBox(width: 50),
                            pw.Text("${billingDetails.qty}",
                                style: pw.TextStyle(
                                  fontSize: 10,
                                )),
                            pw.SizedBox(width: 10),
                            pw.Text("${billingDetails.price}",
                                style: pw.TextStyle(
                                  fontSize: 10,
                                )),
                            pw.SizedBox(width: 10),
                            pw.Text("${(billingDetails.qty) *
                                (billingDetails.price)}",
                                style: pw.TextStyle(
                                  fontSize: 10,
                                )),
                            pw.SizedBox(width: 10),
                          ]),
                          pw.Padding(
                            padding: pw.EdgeInsets.only(top: 10, bottom: 10),
                            child: pw.Divider(
                                color: PdfColors.black, thickness: 0.5),
                          ),
                        ]));
                  }).toList()),
              pw.Divider(color: PdfColors.black, thickness: 2),
              pw.Row(mainAxisAlignment: pw.MainAxisAlignment.end,
                  crossAxisAlignment: pw.CrossAxisAlignment.end,
                  children: [
                    pw.Row(mainAxisAlignment: pw.MainAxisAlignment.spaceBetween,
                        children: [
                          pw.Column(
                              crossAxisAlignment: pw.CrossAxisAlignment.start,
                              children: [
                                pw.Text('TOTAL ', style: pw.TextStyle(
                                    fontSize: 10, fontWeight: FontWeight.bold)),
                                pw.Text("ADVANCE CASH ", style: pw.TextStyle(
                                    fontSize: 10, fontWeight: FontWeight.bold)),
                                pw.Text("REMAINING PAYMENT ", style: pw
                                    .TextStyle(
                                    fontSize: 10, fontWeight: FontWeight.bold)),
                              ]),
                          pw.Column(
                              crossAxisAlignment: pw.CrossAxisAlignment.start,
                              children: [
                                pw.Text(": ${billingData.total}", style: pw
                                    .TextStyle(fontSize: 10)),
                                pw.Text(": ${billingData.advanceCash}",
                                    style: pw.TextStyle(fontSize: 10)),
                                pw.Text(": ${billingData.remaingCash}",
                                    style: pw.TextStyle(fontSize: 10)),
                              ])
                        ]),
                  ])
            ]) // Center
          ];
        })); //
    return await pdf.save();
  }

  // final netImage = await rootBundle.load('');
  // final netImagebyte=netImage.buffer.asUint8List();
  // pw.Image netImg = pw.Image(pw.MemoryImage(netImagebyte));

  Future<void> saveAndLaunchFile(List<int> bytes, String fileName) async {
    final directory = await getApplicationDocumentsDirectory();

//Get directory path
    final path = directory.path;

    print("path:: $path");

//Create an empty file to write PDF data
    File file = File('$path/Bill.pdf');
    print("file:: $file");

//Write PDF data
    await file.writeAsBytes(bytes, flush: true);

//Open the PDF document in mobile
//     OpenFile.open('$path/Product Bill.pdf');
//     OpenFile.open('$path/$fileName');
  }
}
