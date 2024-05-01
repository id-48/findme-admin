import 'package:flutter/material.dart';
import 'package:flutter_mobx/flutter_mobx.dart';
import 'package:find_me_admin/models/footrest/add_footrest/req_footrest.dart';
import 'package:find_me_admin/models/footrest/get_footrest/res_footrest.dart';
import 'package:find_me_admin/models/footrest/update_footrest/req_update_footrest.dart';
import 'package:find_me_admin/network/RestApis.dart';
import 'package:find_me_admin/screens/Admin/add_foot_rest_screen.dart';
import 'package:find_me_admin/utils/Extensions/string_extensions.dart';
import 'package:find_me_admin/utils/ResponsiveWidget.dart';
import 'package:find_me_admin/utils/toast.dart';

import '../../main.dart';
import '../../utils/Colors.dart';
import '../../utils/Common.dart';
import '../../utils/Extensions/app_textfield.dart';
import '../../utils/Extensions/text_styles.dart';

class AddFootRestDialog extends StatefulWidget {
  static String tag = '/AddFootrestDialog';

  final FootRest? footRestData;
  final Function()? onUpdate;

  AddFootRestDialog({this.onUpdate, this.footRestData});

  @override
  State<AddFootRestDialog> createState() => _AddFootRestDialogState();
}

class _AddFootRestDialogState extends State<AddFootRestDialog> {
  GlobalKey<FormState> _formKey = GlobalKey<FormState>();

  TextEditingController footRestController = TextEditingController();

  bool isUpdate = false;
  final borderRadius = BorderRadius.all(Radius.circular(9.0));

  @override
  void initState() {
    super.initState();
    init();
  }

  Future<void> init() async {
    isUpdate = widget.footRestData != null;

    if (isUpdate) {
      footRestController.text = widget.footRestData!.footRest.validate();
    }
  }

  AddFootRestApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);

      String footrest = footRestController.text.trim();

      ReqFootrest footrestData = await ReqFootrest(
          footRest: footrest
      );

      await addFootrest(req: footrestData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");

          Navigator.pushNamed(context, AddFootRestScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }

  UpdateFootResstApi() async {
    if (_formKey.currentState!.validate()) {
      appStore.setLoading(true);
      String footRest = footRestController.text.trim();


      ReqUpdateFootrest updateFootrestsData = ReqUpdateFootrest(
        footRestId: widget.footRestData!.id,
        footRest: footRest,

      );

      await updateFootrest(req: updateFootrestsData).then((value) {
        appStore.setLoading(false);
        if (value.status == true) {
          ToastUtils.showCustomToast(context, value.message, "success");
          Navigator.pushNamed(context, AddFootRestScreen.route);
        } else {
          ToastUtils.showCustomToast(context, value.message, "warning");
        }
      });
    }
  }


  @override
  void setState(fn) {
    if (mounted) super.setState(fn);
  }

  @override
  Widget build(BuildContext context) {
    return AlertDialog(
      actionsPadding: EdgeInsets.only(right: 16, bottom: 16),
      title: Row(
        mainAxisAlignment: MainAxisAlignment.spaceBetween,
        children: [
          Text("Add Foot rest Details",
              style: boldTextStyle(color: primaryColor, size: 20)),
          IconButton(
            icon: Icon(Icons.close),
            padding: EdgeInsets.zero,
            onPressed: () {
              Navigator.pop(context, false);
            },
          ),
        ],
      ),
      content: Observer(builder: (context) {
        return SingleChildScrollView(
          child: Stack(
            children: [
              Visibility(
                visible: !appStore.isLoading,
                child: Form(
                  key: _formKey,
                  child: SizedBox(
                    width: ResponsiveWidget.isMediumScreen(context)
                        ? getBodyWidth(context)
                        : (getBodyWidth(context) - 48) * 0.4,
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      mainAxisSize: MainAxisSize.min,
                      children: [
                        Text("Foot rest", style: primaryTextStyle()),
                        SizedBox(height: 8),
                        AppTextField(
                          controller: footRestController,
                          textFieldType: TextFieldType.NAME,
                          decoration: commonInputDecoration(),
                          textInputAction: TextInputAction.next,
                          errorThisFieldRequired: "This field is required",
                        ),
                        SizedBox(height: 16),

                      ],
                    ),
                  ),
                ),
              ),
              Visibility(visible: appStore.isLoading, child: loaderWidget()),
            ],
          ),
        );
      }),
      actions: <Widget>[
        dialogSecondaryButton("Cancel", () {
          Navigator.pop(context, false);
        }),
        SizedBox(width: 4),
        dialogPrimaryButton(isUpdate ? "Update" : "Add", () {
          isUpdate ? UpdateFootResstApi() : AddFootRestApi();
        }),
      ],
    );
  }
}
