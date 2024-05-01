import 'dart:typed_data';

import 'package:cached_network_image/cached_network_image.dart';
import 'package:flutter/material.dart';
import 'package:http/http.dart' as http;
import 'package:lottie/lottie.dart';

import '../main.dart';
import '../utils/Colors.dart';
import '../utils/Extensions/constants.dart';
import '../utils/Extensions/context_extensions.dart';
import '../utils/Extensions/int_extensions.dart';
import '../utils/Extensions/string_extensions.dart';
import '../utils/Extensions/widget_extensions.dart';
import 'Extensions/colors.dart';
import 'Extensions/common.dart';
import 'Extensions/decorations.dart';
import 'Extensions/text_styles.dart';
import 'ResponsiveWidget.dart';

getMenuWidth() {
  return appStore.isMenuExpanded ? 270.00 : 80.00;
}

getBodyWidth(BuildContext context) {
  return MediaQuery
      .of(context)
      .size
      .width - getMenuWidth();
}

double getTableWidth(context) {
  return ResponsiveWidget.isLargeScreen(context) ? (getBodyWidth(context) -
      48) * 0.5 : getBodyWidth(context) - 16;
}

double getWalletTableWidth(context) {
  return ResponsiveWidget.isLargeScreen(context) ? (getBodyWidth(context) -
      40) * 0.8 : getBodyWidth(context) - 16;
}

double getDetailWidth(context) {
  return ResponsiveWidget.isLargeScreen(context) ? (getBodyWidth(context) -
      40) * 0.2 : getBodyWidth(context) - 16;
}

double? getTableHeight(context) {
  return ResponsiveWidget.isLargeScreen(context) ? 570 : null;
}

Widget commonButton(String title, Function() onTap, {double? width}) {
  return SizedBox(
    width: width,
    child: ElevatedButton(
      style: ElevatedButton.styleFrom(
        shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(defaultRadius)),
        elevation: 0,
        padding: EdgeInsets.symmetric(vertical: 20),
        backgroundColor: primaryColor,
      ),
      child: Text(title, style: boldTextStyle(color: Colors.white)),
      onPressed: onTap,
    ),
  );
}

List<BoxShadow> commonBoxShadow() {
  return [BoxShadow(color: Colors.black12, blurRadius: 2.0, spreadRadius: 0)];
}

containerDecoration() {
  return BoxDecoration(
    borderRadius: BorderRadius.circular(defaultRadius),
    color: Colors.white,
    border: Border.all(color: viewLineColor, width: 1.5),
  );
}

Widget commonCachedNetworkImage(String? url,
    {double? height, double? width, BoxFit? fit, AlignmentGeometry? alignment, bool usePlaceholderIfUrlEmpty = true, double? radius}) {
  if (url != null && url.isEmpty) {
    return placeHolderWidget(height: height,
        width: width,
        fit: fit,
        alignment: alignment,
        radius: radius);
  } else if (url.validate().startsWith('http')) {
    return CachedNetworkImage(
      imageUrl: url!,
      height: height,
      width: width,
      fit: fit,
      alignment: alignment as Alignment? ?? Alignment.center,
      errorWidget: (_, s, d) {
        return placeHolderWidget(height: height,
            width: width,
            fit: fit,
            alignment: alignment,
            radius: radius);
      },
      placeholder: (_, s) {
        if (!usePlaceholderIfUrlEmpty) return SizedBox();
        return placeHolderWidget(height: height,
            width: width,
            fit: fit,
            alignment: alignment,
            radius: radius);
      },
    );
  } else {
    return Image.network(url!, height: height,
        width: width,
        fit: fit,
        alignment: alignment ?? Alignment.center);
  }
}

Widget placeHolderWidget(
    {double? height, double? width, BoxFit? fit, AlignmentGeometry? alignment, double? radius}) {
  return Image.asset('assets/placeholder.jpg', height: height,
      width: width,
      fit: fit ?? BoxFit.cover,
      alignment: alignment ?? Alignment.center);
}

Widget informationWidget(String title, String value) {
  return Padding(
    padding: EdgeInsets.only(bottom: 8),
    child: Row(
      mainAxisAlignment: MainAxisAlignment.spaceBetween,
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Expanded(
          child: Text(title, style: boldTextStyle(weight: FontWeight.w500)),
        ),
        Expanded(
          child: Text(value, style: primaryTextStyle()),
        ),
      ],
    ),
  );
}

Widget addButton(String title, Function() onTap) {
  return InkWell(
    child: Container(
      padding: EdgeInsets.symmetric(horizontal: 16, vertical: 8),
      decoration: BoxDecoration(color: primaryColor,
          borderRadius: BorderRadius.circular(defaultRadius)),
      child: Row(
        mainAxisSize: MainAxisSize.min,
        children: [
          Icon(Icons.add, color: Colors.white),
          SizedBox(width: 12),
          Text(title, style: boldTextStyle(color: Colors.white)),
        ],
      ),
    ),
    onTap: onTap,
  );
}

Widget dialogSecondaryButton(String title, Function() onTap) {
  return SizedBox(
    width: 120,
    height: 40,
    child: ElevatedButton(
      style: ElevatedButton.styleFrom(
          shape: RoundedRectangleBorder(
              borderRadius: BorderRadius.circular(defaultRadius),
              side: BorderSide(color: viewLineColor)),
          elevation: 0,
          backgroundColor: Colors.transparent,
          shadowColor: Colors.transparent),
      child: Text(title, style: boldTextStyle(color: Colors.grey)),
      onPressed: onTap,
    ),
  );
}

Widget dialogPrimaryButton(String title, Function() onTap, {Color? color}) {
  return SizedBox(
    width: 120,
    height: 40,
    child: ElevatedButton(
      style: ElevatedButton.styleFrom(
        shape: RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(defaultRadius)),
        elevation: 0,
        backgroundColor: color ?? primaryColor,
      ),
      child: Text(title, style: boldTextStyle(color: Colors.white)),
      onPressed: onTap,
    ),
  );
}

Widget loaderWidget() {
  return Center(
      child: Lottie.asset('assets/loader.json', width: 70, height: 70,));
}

Widget emptyWidget() {
  return Center(
      child: Lottie.asset('assets/no_data.json', width: 250, height: 250));
}

Widget backButton(BuildContext context, {bool? value}) {
  return ElevatedButton(
    onPressed: () {
      if (value != null) {
        finish(context, value);
      } else {
        finish(context);
      }
    },
    child: Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        Icon(Icons.arrow_back_ios, color: Colors.white, size: 12),
        SizedBox(width: 8),
        Text("Back", style: primaryTextStyle(color: Colors.white)),
      ],
    ),
    style: ElevatedButton.styleFrom(padding: EdgeInsets.all(12)),
  );
}

Widget scheduleOptionWidget(
    {required BuildContext context, required bool isSelected, required String imagePath, required String title, required Function() onTap}) {
  return GestureDetector(
    onTap: onTap,
    child: Container(
      padding: EdgeInsets.all(24),
      decoration: BoxDecoration(
          borderRadius: BorderRadius.circular(defaultRadius),
          border: Border.all(color: isSelected ? primaryColor : Theme
              .of(context)
              .dividerColor),
          color: Theme
              .of(context)
              .cardColor),
      child: Row(
        mainAxisSize: MainAxisSize.min,
        children: [
          ImageIcon(AssetImage(imagePath), size: 20,
              color: isSelected ? primaryColor : Colors.grey),
          SizedBox(width: 16),
          Text(title, style: boldTextStyle()),
        ],
      ),
    ),
  );
}

double mCommonPadding(BuildContext context) {
  return ResponsiveWidget.isLessMediumScreen(context)
      ? context.width() * 0.02
      : context.width() * 0.13;
}

double mCommonPadding1(BuildContext context) {
  return context.width() * 0.05;
}

InputDecoration commonInputDecoration(
    {Color? fillColor, String? hintText, Widget? suffixIcon, Function()? suffixOnTap, Widget? prefixIcon, Widget? suffix, String? labelText}) {
  return InputDecoration(
    prefixIcon: prefixIcon,
    labelText: labelText,
    contentPadding: EdgeInsets.symmetric(horizontal: 16, vertical: 16),
    filled: true,
    hintText: hintText != null ? hintText : '',
    hintStyle: secondaryTextStyle(),
    fillColor: Colors.grey.withOpacity(0.15),
    counterText: '',
    suffixIcon: suffixIcon,
    enabledBorder: OutlineInputBorder(
        borderSide: BorderSide(style: BorderStyle.none),
        borderRadius: BorderRadius.circular(defaultRadius)),
    focusedBorder: OutlineInputBorder(
        borderSide: BorderSide(color: primaryColor),
        borderRadius: BorderRadius.circular(defaultRadius)),
    errorBorder: OutlineInputBorder(borderSide: BorderSide(color: Colors.red),
      borderRadius: BorderRadius.circular(defaultRadius),),
    focusedErrorBorder: OutlineInputBorder(
        borderSide: BorderSide(color: Colors.red),
        borderRadius: BorderRadius.circular(defaultRadius)),
    errorMaxLines: 2,
    suffixIconColor: textSecondaryColorGlobal,
    prefixIconColor: textSecondaryColorGlobal,
    hoverColor: fillColor ?? editTextBackgroundColor,
    suffix: suffix,
  );
}

Widget clientScheduleOptionWidget(BuildContext context, bool isSelected,
    IconData imagePath, String title) {
  return Container(
    padding: EdgeInsets.symmetric(horizontal: 16, vertical: 10),
    decoration: boxDecorationWithRoundedCorners(
        border: Border.all(color: isSelected ? primaryColor : borderColor),
        backgroundColor: context.cardColor),
    child: Row(
      children: [
        Icon(imagePath, size: 20,
            color: isSelected ? primaryColor : textPrimaryColorGlobal),
        8.width,
        Text(title, style: boldTextStyle(
            color: isSelected ? primaryColor : textPrimaryColorGlobal))
            .paddingTop(2)
            .expand(),
      ],
    ),
  );
}

Widget outlineActionIcon(IconData icon, Color color, String message,
    Function() onTap, {String? title}) {
  return GestureDetector(
    child: Tooltip(
      message: message,
      child: MouseRegion(
        cursor: SystemMouseCursors.click,
        child: Container(
          padding: EdgeInsets.all(4),
          decoration: BoxDecoration(color: color.withOpacity(0.2),
              borderRadius: BorderRadius.circular(8),
              border: Border.all(color: color)),
          child: Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              Icon(icon, color: color, size: 16),
              if (!title.isEmptyOrNull) 4.width,
              if (!title.isEmptyOrNull) Text(
                  title.validate(), style: boldTextStyle(color: color)),
              if (!title.isEmptyOrNull) 4.width,
            ],
          ),
        ),
      ),
    ),
    onTap: onTap,
  );
}

Widget mHeading(String value) {
  return Column(
    crossAxisAlignment: CrossAxisAlignment.start,
    children: [
      Text(value, style: boldTextStyle(
          size: 35, letterSpacing: 1.5, weight: FontWeight.w500)),
      8.height,
      Row(
        children: [
          Container(width: 90,
              height: 4,
              decoration: boxDecorationWithRoundedCorners(
                  borderRadius: radius(8), backgroundColor: primaryColor)),
          8.width,
          Container(width: 25,
              height: 4,
              decoration: boxDecorationWithRoundedCorners(
                  borderRadius: radius(8), backgroundColor: primaryColor))
        ],
      ),
      20.height,
    ],
  );
}


Future<Uint8List> imageDataURLtoUint8List(String url) async {
  final urlData = Uri.parse(url);
  http.Response response = await http.get(urlData);
  if (response.statusCode == 200) {
    final jsonResponse = response.bodyBytes;
    return jsonResponse;
  }
  return Uint8List(0);
}


